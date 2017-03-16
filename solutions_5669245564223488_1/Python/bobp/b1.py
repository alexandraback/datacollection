#!/usr/bin/python
import sys
import math
import heapq 
import fractions
import copy
import argparse
import IPython
import ipdb

sys.setrecursionlimit(5000)

author="@".join(["bobp"+"fled","gmail.com"])

class solver:
    """ implements case specific code """
    def __init__(self):
        global pc
        self.pc = pc

    def parse(self):
        [self.n]=map(int,getline().split());
        self.ss=map(str,getline().split());

    def makestring(self, ss):
        if(ss):
            for i in range(len(ss)):
                for rest in self.makestring(ss[:i]+ss[i+1:]):
                    yield ss[i]+rest
        else:
            yield ""

    def isrepeat(self,s):
        return s==(s[0]*len(s))

    def checkstring(self, s):
        a=s[0]
        done=set()
        for b in s[1:]:
            if(a!=b):
                if(a in done):
                    return False
                done.add(a)
                a=b
        if(a in done):
            return False
        return True
    
    def rmrepeats(self, s):
        a=s[0]
        out=a
        for b in s[1:]:
            if(a!=b):
                a=b
                out=out+a
        debug("rmrepeats",s,out)
        return out
    
    def solve(self):
        count = 1
        ends={}
        starts={}
        repeats={}
        used=set()
        tot_repeats=0
        for i in range(len(self.ss)):
            s=self.ss[i]
            ret=self.checkstring(s)
            if(not ret):
                debug("A")
                return 0
            if(self.isrepeat(s)):
                tot_repeats+=1
                if(s[0] in repeats):
                    repeats[s[0]]+=1
                    count=count*repeats[s[0]]
                else:
                    repeats[s[0]]=1
            else:
                if(s[-1]) in ends:
                    debug("B")
                    return 0
                else:
                    ends[s[-1]]=[i]
                if(s[0]) in starts:
                    debug("B2")
                    return 0
                else:
                    starts[s[0]]=[i]
        combines=0
        for i in repeats.keys():
            used.add(i)
            if(i in ends):
                debug("combine",i)
                combines+=1
        used|=set(ends.keys())
        for i in range(len(self.ss)):
            s=self.rmrepeats(self.ss[i])
            if(self.isrepeat(s)):
                continue
            if (s[0] in ends or s[0] in repeats):
                debug("combine",s)
                combines+=1
            else:
                if(s[0] in used):
                    debug("C",s,ends)
                    return 0
                used.add(s[0])
            last=s[0]
            for c in s[1:-1]:
                if(c!=last):
                    if(c) in used:
                        debug("D")
                        return 0
                    used.add(c)
                    last=c
        num=len(self.ss)-combines-tot_repeats+len(repeats)
        debug(num,len(self.ss),combines,tot_repeats,repeats)
        if(num==0):
            return 0
        assert num>0
        for i in range(num):
            count=count*(i+1)
        return count%1000000007

class precomputer:
    """ 
    implements code that is not case specific such as generating a large
    table that can be used by all testcases
    """
    def __init__(self):
        debug("precomputer.__init__()",level=5)

def main():
    [cases]=map(int,getline().split());
    for caseid in range(1,cases+1):
        docase=(args.testcase is None or caseid in args.testcase)
        if docase:
            debug("Start Case:",caseid,level=5)
        s=solver()
        s.parse()
        if docase:
            debug("Solving Case:",caseid,level=5)
            result=s.solve()
            putline("Case #"+str(caseid)+": "+str(result))

def getline():
    line=args.infile.readline()
    debug("input:",line,level=5,nl=0)
    return line
    

def putline(*arg,**keywords):
    try:
        nl=keywords["nl"];
    except KeyError:
        nl=1
    line=" ".join(map(str,arg))
    if(nl):
        line+='\n'
    args.outfile.write(line)
    debug("output:",line,level=5,nl=0)

def put(*arg):
    putline(*arg,nl=0)

def debug(*arg,**keywords):
    try:
        level=keywords["level"];
    except KeyError:
        level=10
    try:
        nl=keywords["nl"];
    except KeyError:
        nl=1
    if(args.debug>=level):
        args.dbgfile.write(' '.join(map(str,arg)))
        if(nl):
            args.dbgfile.write('\n')

def doargs(argv=sys.argv[1:]):
    global args
    parser=argparse.ArgumentParser(description="solution by "+author)
    parser.add_argument("infile",nargs='?',type=argparse.FileType("r"),default=sys.stdin)
    parser.add_argument("outfile",nargs='?',type=argparse.FileType("w"),default=sys.stdout)
    parser.add_argument("-t",'--testcase',type=int,action="append")
    parser.add_argument("-d",'--debug',type=int,default=8)
    parser.add_argument("-i",'--interactive',action="store_true")
    parser.add_argument("-ipdb","--ipdb",action="store_true")
    parser.add_argument("dbgfile",nargs='?',type=argparse.FileType("w"),default=sys.stderr)
    args=parser.parse_args(argv)

def cleanup():
    if(args.infile!=sys.stdin):
        args.infile.close()
    if(args.outfile!=sys.stdout):
        args.outfile.close()
    if(args.dbgfile!=sys.stderr):
        args.dbgfile.close()

def setup():
    global pc
    try:
        pc
    except NameError:
        pc=precomputer()
    pass;

def run(argstring=None):
    if(not argstring is None):
        doargs(argstring.split())
    if(args.ipdb):
        ipdb.set_trace()
    setup()
    main()
    cleanup()
    if(args.ipdb):
        ipdb.set_trace()

if __name__=="__main__":
    from IPython.core import ultratb
    sys.excepthook = ultratb.FormattedTB(mode='Verbose',color_scheme='Linux', call_pdb=1)
    doargs()
    setup()
    if(args.interactive):
        IPython.embed()
    else:
        run()
