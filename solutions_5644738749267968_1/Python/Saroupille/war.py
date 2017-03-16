f=open("test2war.in", "r")
n_test=int(f.readline())

def computeD(ken, naomi):
    #print(ken)
    #print(naomi)
    score=0
    while naomi!=list():
        if naomi[0]<ken[0]:
            naomi.pop(0)
            ken.pop(len(ken)-1)
        else:
            score+=1
            naomi.pop(0)
            ken.pop(0)
    print(score)
    return str(score)

def compute(ken,naomi):
    score=0
    while naomi!=list():
        last=len(naomi)-1
        if naomi[last]>ken[last]:
            naomi.pop(last)
            ken.pop(0)
            score+=1
        else:
            naomi.pop(last)
            ken.pop(last)
    print(score)
    return str(score)

for i in range(n_test):
    size=int(f.readline())
    naomi=sorted(list(map(float, f.readline().split(" "))))
    ken=sorted(list(map(float, f.readline().split(" "))))
    resultD=computeD(list(ken),list(naomi))
    result=compute(ken,naomi)
    w=open("result.txt", "a")
    s="Case #"+str(i+1)+": "+resultD+" "+result+"\n"
    w=open("result.txt", "a")
    w.write(s)
    w.close()
f.close()
