#fi=open("D-large.in"); fo=open("D-large.out","w")
fi=open("D-small-attempt0.in"); fo=open("D-small-attempt0.out","w")

for T in range(int(fi.readline())):
    k,c,s=map(int,fi.readline().split())
    print("Case #"+str(T+1)+":",' '.join(map(str,range(1,s+1))),file=fo)

fi.close()
fo.close()
print("OK")