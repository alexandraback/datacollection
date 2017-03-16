#flipping up to index i: (i<N, where N - total length)
import os
os.chdir("D:/Code Jam/Qual_round_task2")
def readFile(f):
    result=[]
    with open(f) as handle:
        T=int(handle.readline())
        for t in range(T):
            res=handle.readline().strip("\n")
            result.append(res)
    return result
data=readFile("B-small-attempt2.in")
print data

def Simplify(s):
    simplified=s[0]
    for ch in s[1:]:
        if ch!=simplified[-1:]:
            simplified+=ch
    return simplified


def Solve(dat):
    flips=0
    dat=Simplify(dat)
    if dat=="+":
        return flips
    if dat[0]=="-":
        flips+=1
        dat=dat[1:]
    flips+=2*sum([d=="-" for d in dat])
    return flips


with open("output.txt","w") as handle:
    n=0
    for dat in data:
        n+=1
        i = Solve(dat)
        string="Case #%s: %s\n"%(n,i)
        print string
        handle.write(string)
    