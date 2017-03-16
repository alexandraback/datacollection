filename  = "A-small-attempt0.in"#"B-large-practice.in"
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
for C in range(T):
    S=f.readline()
    count  = [0]*10
    count[0] = S.count('Z')
    count[2] = S.count('W')
    count[4] = S.count('U')
    count[6] = S.count('X')
    count[8] = S.count('G')
    count[5] = S.count('F')-count[4]
    count[7] = S.count('V')-count[5]
    count[9] = S.count('I')-count[5]-count[6]-count[8]
    count[3] = S.count('R')-count[0]-count[4]
    count[1]=S.count('O')-count[0]-count[2]-count[4]
    ret  = ''.join([str(i)*count[i] for i in range(10)])
    print("Case #"+str(C+1)+": "+ret+"\n")
    out.write("Case #"+str(C+1)+": "+ret+"\n")
f.close()
out.close()
