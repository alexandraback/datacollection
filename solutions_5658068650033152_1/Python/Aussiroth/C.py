import math

infile = open("C-large.in", "r")
outfile = open("Cout1.txt", "w")

total=0
t = int(infile.readline().rstrip())
for z in range(1, t+1):

    #IO here
    raw = infile.readline().split()
    n, m, k = int(raw[0]), int(raw[1]), int(raw[2])
    if m>n:
        n, m = m,n
    if n==1 or m==1 or n==2 or m==2 or k<5:
        solution = k
    else:
        """if k<11:
            temp = k-2
            solution = math.floor(temp/3)
            if solution+2<=n:
                solution = 2*solution+2+temp%3
            else:
                solution-=1
                enclosed = 2*solution+2+solution
                solution = 2*solution+2
                solution += k-(enclosed)
                solution= int(solution)"""
        if m==100000:
            solution=0
        else:
            a = 1
            b = 1
            while a*b+2*a+2*b<k:
                if a>b:
                    b+=1
                else:
                    a+=1
            if a+2<=n and b+2<=m:
                solution = 2*a+2*b
                if (a*b+2*a+2*b)-k>=2:
                    solution-=(a*b+2*a+2*b-k)//2
            else:
                if a+2>n:
                    a-=(a+2-n)
                if b+2>m:
                    b-=(b+2-m)
                if a==1 or b==1:
                    temp = k-2
                    solution = math.floor(temp/3)
                    if solution+2<=n:
                        solution = 2*solution+2+temp%3
                    else:
                        solution-=1
                        enclosed = 2*solution+2+solution
                        solution = 2*solution+2
                        solution += k-(enclosed)
                        solution= int(solution)
                else:
                    solution = 2*a+2*b
                    solution += k-(a*b+2*a+2*b)
    output = "Case #"+str(z)+": "+str(solution)+"\n"
    print(output)
    outfile.write(output)

infile.close()
outfile.close()
