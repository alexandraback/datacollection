import sys
import math

def print_answer(answer):
    print "Case #"+str(ii+1)+": "+str(answer)
    fout.write("Case #"+str(ii+1)+": "+str(answer)+"\n")

def solve_case(P, Q):
    if Q%2 != 0:
        print_answer("impossible")
    else:
        for i in range(40):
            if (P/Q*2**i)%1.0 == 0:
                inverse = float(Q/P)
                exponent = math.log(inverse,2)
                answer = int(math.ceil(exponent))
        
                print_answer(answer)
                return
        
        print_answer("impossible")

f = open("A-large.in")
fout = open("output.txt", "w")
T = int(f.readline().rstrip())


for ii in range(T):
    line_list = f.readline().rstrip().split("/")
    P = float(line_list[0])
    Q = float(line_list[1])
    solve_case(P,Q)

fout.close()
