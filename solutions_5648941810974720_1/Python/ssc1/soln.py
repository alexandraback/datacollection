from collections import Counter as ct
l=["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
g=map(str,range(0,10))
def f(a,b):
    tp=ct()
    for i in b.keys():
        tp[i]=a*b[i]
    return tp
#l=map(lambda x:ct(x),l)
for i in range(int(raw_input())):
    c=ct(raw_input())
    d=ct()
    ans=[0]*10
    ans[0]=c['Z']
    ans[2]=c['W']
    ans[8]=c['G']
    ans[6]=c['X']
    ans[4]=c['U']
    ans[3]=c['H']-ans[8]
    ans[5]=c['F']-ans[4]
    ans[7]=c['V']-ans[5]
    ans[1]=c['O']-ans[2]-ans[4]-ans[0]
    ans[9]=(c['N']-ans[1]-ans[7])/2
    #print ans
    assert(len(filter(lambda a:a>=0,ans))==10)
    assert(ct("".join(map(lambda a,b: a*b,ans,l)))==c)
    print "Case #{}: {}".format(str(i+1),"".join(map(lambda a,b:a*b,ans,g)))