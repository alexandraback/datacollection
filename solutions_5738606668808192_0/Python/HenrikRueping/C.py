filename  = "C-small-attempt0.in"#"C-small-attempt0.in"#"B-large.in"
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
thend=" 3 4 5 6 7 8 9 10 11"
for i in range(T):
    out.write("Case #"+str(i+1)+":\n")
    [N,J]=[int(a)  for a in f.readline().split()]
    for i in range(min(J,2**(N//2-1))):
        S= "{0:b}".format(i)
        S= "0"*(N//2-1-len(S))+S
        S = "1"+S+S[::-1]+"1"
        print(S+" 3 4 5 6 7 8 9 10 11")
        out.write(S+" 3 4 5 6 7 8 9 10 11\n")
f.close()
out.close()
