file = open('A-small-attempt0.in.txt','r')
file_out = open('out1.txt','w')
file = file.readlines()
n = int(file[0])
for j in range(1,n+1):
    S = file[j].strip() 
    S = list(S)
    l0=S[0]
    lastword=S[0]
    for l in S[1:]:
        if l<l0:
            lastword+=l
        else:
            lastword = l+lastword
            l0 = l
        

    file_out.write('Case #%i: %s\n'%(j,lastword))