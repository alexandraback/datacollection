import sys
from gdata.geo import Pos

def unPaso(pos, key, tar, le):
    l=[]
    mm=0
    su=0
    for i in pos:
        for j in key:
            qq=i+j
            ca=0
            for let in xrange(len(qq)-len(tar)+1):
                if qq[let:len(tar)+let]==tar: ca+=1
            l.append(qq)
            if ca>mm:
                mm=ca
            su+=ca
    if le==len(l[0]):
        return float(mm*len(l)-su)/len(l)
    return unPaso(l, key, tar, le)

def main(lines):
    k, l, s = map(lambda x : int(x), lines[0].split())
    key = lines[1]
    target = lines[2]
    for i in target:
        if not i in key: return 0
    if s<l: return 0
    if s==1:
        return float(len(key)-key.count(target))/len(key)
    pos=[]
    for i in key:
        pos.append(i)
    pos=unPaso(pos, key, target, s)
    return pos 

if __name__ == "__main__":
   filename = sys.argv[1]
   with open(filename, "r") as f:
       f.readline()
       i = 0
       lines = []
       for l in f.readlines():
           i += 1
           lines.append(l.strip())
           if i % 3 == 0:
               print "Case #" + str(i / 3) + ": " + str(main(lines))
               lines = [] 
