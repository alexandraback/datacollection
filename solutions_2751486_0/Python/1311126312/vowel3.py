data=open("vowel.in").readlines()
out=open("vowel.out","w")
c=1
for i in data[1:]:
    stringo=i.split()[0]
    print stringo
    n=int(i.split()[1])
    print n
    co=0
    vo=0
    al=[]
    for j in stringo:
        if j in 'aeiou':
            if co!=0:
                al.append(co)
                co=0
            vo+=1
        else:
            if vo!=0:
                al.append(vo)
                vo=0
            co+=1
    if vo or co:
        al.append(vo+co)
    iv=0
    if (stringo[0] in "aeiou"): iv=1
    print iv
    string=''
    for i in al:
      if iv%2==0: string+=i*"n"
      else: string+=i*"a"
      iv+=1
    print string
    l=len(string)
    a=0
    for j in range(0,l):
        for k in range(j, l+1):
            if "n"*n in string[j:k]:
                a+=1
    print "Case #"+str(c)+": "+str(a)+"\n"
    out.write("Case #"+str(c)+": "+str(a)+"\n")
    c+=1
