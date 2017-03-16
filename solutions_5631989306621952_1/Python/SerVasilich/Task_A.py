#fi=open("A-large.in"); fo=open("A-large.out","w")
fi=open("A-small-attempt0.in"); fo=open("A-small-attempt0.out","w")

def fnd(s):
    t=s[0]    
    for i in range(1,len(s)):
        if s[i]>=t[0]: t=s[i]+t
        else: t+=s[i]
    return t    
for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",fnd(fi.readline().strip()),file=fo)
fi.close()
fo.close()
print("OK")