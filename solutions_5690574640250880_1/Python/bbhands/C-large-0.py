#!/usr/bin/python
# -*- coding: utf-8 -*-

if __name__ == "__main__":

    fin = open("C-large-0.in", "r")
    fout = open("C-large-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        params = map(int, fin.readline().strip().split(' '))
        R, C, M = tuple(params)
        answer = []
        if R==1 or C==1:
            if M == R*C - 1: 
                if C==1:
                    answer = ["*"]*M
                    answer.append("c")
                else:
                    answer = ["*"*M + "c"]
            elif C==1:
                answer = ["*"]*M
                answer.extend(["."]*(R-M-1))
                answer.append("c")
            else:
                answer = ["*"*M + "."*(C-M-1) + "c"]
        else:
            if M == R*C - 1:
                answer = ["*"*C]*(R-1)
                answer.append("*"*(C-1)+"c")
            elif M > R*C - 4:
                answer = ["Impossible"]
            elif M == R*C-5 or M == R*C-7:
                answer = ["Impossible"]
            elif (R==2 or C==2) and M%2==1:
                answer = ["Impossible"]
            else:
                rows = M/C
                if rows>=R-2:
                    answer = ["*"*C]*(R-3) if R>=3 else []
                    remains = M - C*(R-2)
                    cols = remains/2
                    if remains%2==1:
                        answer.append("*" * (C-3) + "."*3)
                        answer.append("*" * (cols+2) + "." * (C-cols-2))
                        answer.append("*" * (cols+2) + "." * (C-cols-3) + "c")
                    else:
                        if R>=3:
                            answer.append("*" * C)
                        answer.append("*" * cols + "." * (C-cols))
                        answer.append("*" * cols + "." * (C-cols-1) + "c")
                else:
                    answer = ["*"*C]*rows
                    remains = M - C*rows
                    if remains == C-1:
                        if rows+3 < R:
                            answer.append("*"*(C-2)+"..")
                            answer.append("*"+"."*(C-1))
                            if R-rows-3>0:
                                answer.extend(["."*C]*(R-rows-3))
                            answer.append("."*(C-1)+"c")
                        
                        else:
                            answer.append("*"*(C-3)+"...")
                            answer.append("*"+"."*(C-1))
                            answer.append("*"+"."*(C-2)+"c")


                    else:
                        answer.append("*"*remains+"."*(C-remains))
                    
                        if R-rows-2>0:
                            answer.extend(["."*C]*(R-rows-2))
                        
                        answer.append("."*(C-1)+"c")

        fout.write("Case #%i:\n" % (t+1))
        fout.write("\n".join(answer))
        fout.write("\n")
    
    fin.close()
    fout.close()

