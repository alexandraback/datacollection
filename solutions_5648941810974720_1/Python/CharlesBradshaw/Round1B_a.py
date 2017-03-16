fin= open("A-large (3).in",'r')
fout=open("round1B_A.out",'w')
T = int(fin.readline())
for t in range(T):
    a = (fin.readline()).rstrip()
    letters = [0]*26;
    for l in range(26):
        letters[l]=sum([1 for i in a if ord(i) == (ord('A')+l)])
    count = [0]*10
    count[0]=letters[ord('Z')-ord('A')]
    count[2]=letters[ord('W')-ord('A')]
    count[6]=letters[ord('X')-ord('A')]
    count[8]=letters[ord('G')-ord('A')]
    count[4]=letters[ord('U')-ord('A')]
    count[5]=letters[ord('F')-ord('A')]-count[4]
    count[7]=letters[ord('V')-ord('A')]-count[5]
    count[1]=letters[ord('O')-ord('A')]-count[0]-count[2]-count[4]
    count[3]=letters[ord('H')-ord('A')]-count[8]
    count[9]=(letters[ord('N')-ord('A')]-count[1]-count[7])/2
    stri = ''.join([''.join([str(i)]*count[i]) for i in range(10)])
    #%print stri
    fout.write("Case #"+str(t+1)+': ' +stri+'\n')
fout.close()
fin.close()
