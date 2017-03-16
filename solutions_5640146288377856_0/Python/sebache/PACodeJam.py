import sys

def main(lines):
    r,c,w = map(lambda x : int(x), lines[0].split())
    if c==1: return 1*r
    if c==2: return 2*r
    if w==1: return c*r
    if w==c: return c*r
    if w==c-1: return c*r
    q=c/w  + 2*(w-1)
    if c%w==0: q-=1
    return q*r
    
if __name__ == "__main__":
   filename = sys.argv[1]
   with open(filename, "r") as f:
       f.readline()
       i = 0
       lines = []
       for l in f.readlines():
           i += 1
           lines.append(l.strip())
           print "Case #" + str(i) + ": " + str(main(lines))
           lines=[]
