def trans():
    l1=["ejp","mysljylc","kd","kxveddknmc","re","jsicpdrysi","rbcpc","ypc","rtcsra","dkh","wyfrepkym","veddknkmkrkcd","de","kr","kd","eoya","kw","aej","tysr","re","ujdr","lkgc","jv"]
    s2="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"
    l2=s2.split(" ")
    d={}
    for i in range(len(l1)):
        for a in range(len(l1[i])):
            if not d.has_key(l1[i][a]):
                d[l1[i][a]]=l2[i][a]
    d["q"]="z"
    d["z"]="q"
    return d

def test():
    filea=open('A-small-attempt0.in','r')
    fileb=open('output-Large','w')
    total=int(filea.readline().strip())
    d=trans()
    for case in range(1,total+1):
        ss="Case #"+str(case)+": "
        li=filea.readline().strip()
        for i in li:
            if i==" ":
                ss=ss+" "
            else:
                ss=ss+d[i]
        fileb.write(ss+"\n")