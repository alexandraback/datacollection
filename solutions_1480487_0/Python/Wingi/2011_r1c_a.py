import sys, StringIO, re


class SquareTiles(object):
    def __init__(self, lines, l, r):
        self.lines = lines
        self.l = l
        self.r = r
        self.square = "##(%s)##" % "."*(r-2)

    def run(self):
        for i in range((self.l-1)*self.r):
            if (self.lines[i]=="#" and 
                self.lines[i+1]=="#" and
                self.lines[i+self.r]=="#" and 
                self.lines[i+self.r+1]=="#"):
                self.lines[i]="/"
                self.lines[i+1]="\\"
                self.lines[i+self.r]="\\"
                self.lines[i+self.r+1]="/"
        ret = self.out()
        if ret.find("#")==-1:
            return ret.strip()
        else:
            return "Impossible"

    def out(self):
        s = ""
        for i in range(len(self.lines)):
            s+=self.lines[i]
            if i%self.r==self.r-1:
                s+="\n"
        return s

if __name__=="__main__":
    fp = StringIO.StringIO("""3
2 3
###
###
1 1
.
4 5
.##..
.####
.####
.##..""")
    fp = sys.stdin
    for case in range(int(fp.readline())):
        l, r = map(int, fp.readline().strip().split())
        lines = ""
        for i in range(l):
            lines += fp.readline().strip()
        game = SquareTiles(list(lines), l, r)
        print "Case #%d:\n%s" % (case+1, game.run())
