def readFile(f):
    with open(f) as handle:
        T=int(handle.readline())
        string=handle.readline().split(" ")
        N=int(string[0])
        J=int(string[1])
    return (T,N,J)
T,N,J=readFile("C-small-attempt0.in")
print T,N,J

N=16
J=50
#division by 11: sum of even digits has to be equal to the sum of odd digits.
#here 11 is interpreted as it should be in the corresponding base. For base 10 it is "eleven", for base 2 - "three", etc 
#generate J numbers that divide by 11:
numbers=[]
for i in range(1,J+1):
    x=bin(i)
    x=x[2:]
    x="0"*((N-2)/2-len(x))+x
    y=""
    for ch in x:
        y+=ch*2
    y="1"+y+"1"
    numbers+=[y]
    #print y

with open("output.txt","w") as handle:
    string1="Case #1:\n"
    print string1
    handle.write(string1)
    for j in range(J):
        string2=numbers[j]+" 3"+" 4"+" 5"+" 6"+" 7"+" 8"+" 9"+" 10"+" 11\n"
        print string2
        handle.write(string2)