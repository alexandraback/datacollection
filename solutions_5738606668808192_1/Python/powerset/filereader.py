with open('/Users/Justin/projects/codejam/C-small-attempt0.in', 'r+') as f:
    lines = list(f)

T=lines.pop(0).strip()
lines = [ l.strip() for l in lines]

cases=[]
for i in range( int(T) ):
    N, J = lines.pop(0).split()

#    cases.append({'S': S })
N, J, = 32, 500

def solve(N, J):
    scount = 0
    solution = ""
    for i in range(2**(N-1) + 1, 2**N, 2):
        if scount == J:
            print ("Finished: " + str(scount) )
            return solution
        divisors = []
        coin = bin(i)[2:]
        for j in range (2,11):
            basecoin = int(coin, j)
            for k in range(2, 2**15):
                if basecoin % k == 0:
                    #print ( coin + " (" + str(basecoin) + ") is divisible by: " + str(k) )
                    divisors.append(str(k) )
                    break
            if j > len(divisors) + 1:
                #print "do we get here? ", str(j), " ".join(divisors)
                break
            if len(divisors) == 9:
                solution += coin + " " + " ".join(divisors) + "\n"
                scount += 1
                print ( coin + " " + " ".join(divisors) + "\n" )

solution = solve(N, J)

out = open('/Users/Justin/projects/codejam/output.out', 'w')

out.write("Case #1:\n")

out.write(solution)


#j=0
#for c in cases:
#    j+=1
#    st= 'Case #'+str(j)+': '+solve(c)+'\n'
#    print st
#    out.write(st)

