import sys
#sys.stdout = open("out.txt", "w")

def solve(s):
    cnt = {}
    for c in "ZWUXGOHFIVS":
        cnt[c]=0
    for c in s:
        if c in cnt:
            cnt[c]+=1
    icnt = {}
    for i in range(10):
        icnt[i]=0
    icnt[0]=cnt['Z']
    icnt[2]=cnt['W']
    icnt[4]=cnt['U']
    icnt[6]=cnt['X']
    icnt[8]=cnt['G']
    icnt[7]=cnt['S']-icnt[6]
    icnt[5]=cnt['V']-icnt[7]
    icnt[3]=cnt['H']-icnt[8]
    icnt[1]=cnt['O']-(icnt[0]+icnt[2]+icnt[4])
    icnt[9]=cnt['I']-(icnt[5]+icnt[6]+icnt[8])
    ans=""
    for i in range(10):
        for j in range(icnt[i]):
            ans+=str(i)
            
    return ans
    


lines = []

with open("A-small-attempt0.in", "r") as f:
    lines = f.readlines()

n = int(lines[0])
l=""
for i in range(1, n+1):
    ans = solve(lines[i].strip())
    l+="Case #{}: {}\n".format(i, str(ans))

with open("out.txt","w") as f:
    f.write(l)