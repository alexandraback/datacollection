f = open('A-small-attempt2.in','r')

a = f.read()
f.close()
b = a.split('\n')

cases = (int)(b[0])

unknownE = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
unknownD = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

encrypted = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
decrypted = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

encrypted += "yeq"
decrypted += "aoz"

for i in range(len(unknownE)-1,-1,-1):
    if(encrypted.find(unknownE[i])!=-1):
        unknownE.pop(i)

for i in range(len(unknownD)-1,-1,-1):
    if(decrypted.find(unknownD[i])!=-1):
        unknownD.pop(i)

print unknownE
print unknownD

if(len(unknownE)==1 and len(unknownD)==1):
    encrypted += unknownE[0]
    decrypted += unknownD[0]

g = open('A.out','w')

for i in range(1,cases+1):
    output=""
    for j in range(0,len(b[i])):
        x = encrypted.find(b[i][j])
        if(x!=-1):
            output+=decrypted[x]
            

    g.write("Case #"+(str)(i)+": "+output+"\n")

g.close()

