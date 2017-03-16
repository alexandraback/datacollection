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
        [self.p,self.q]=map(int,getline().split("/"));

    def solve(self):
        q=self.q
        p=self.p
        gens=0
        while(q%2==0):
            gens+=1
            q=q/2
        if((p%q)!=0):
            return "impossible"
        p=p/q
        q=1
        while(p>=2):
            p=p/2
            gens-=1
        return gens

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
