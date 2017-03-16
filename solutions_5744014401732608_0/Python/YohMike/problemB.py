import os
import sys
import itertools
import math
import numpy as np
def output_format(answer,test_case):
    output = "Case #%d:" % (test_case+1)
    output += " %s" % answer
    output +="\n"
    return output

def build_matrix_from_graph(d,n):
    matrix = ""
    for i in range(1,n+1):
        for j in range(1,n+1):
            
            if (i,j) in d:
                matrix+= "1"
            else:
                matrix+= "0"
        matrix+="\n"
    return matrix[:-1]

#d = [(1,2),(1,5),(2,4),(4,5),(2,3),(4,3),(3,5)]
#print build_matrix_from_graph(d,5)
def get_n_perms(n,B):
    perm = list(itertools.permutations(range(2,B),n))
    #print perm
    res = []
    for p in perm:
        r = []
        for i,el in enumerate(p):
            if i > 0:
                r.append((p[i-1],el))
        res.append(r)

    return res

print "perms"
print get_n_perms(3,5)

def build_paths(M,B):
    paths = [(1,B)]
    count = 1
    for i in range(2,B):
        paths.append((1,i))
        paths.append((i,B))
        count +=1
        if count == M:
            return paths

    n = 2
    print "paths now", paths
    while count < M:
        p = get_n_perms(n,B)
        print "debug"
        print p
        print paths
        for path in p:
            count +=1
            for t in path:
                #print "t",t
                if t not in paths:
                    paths.append(t)
            if count == M:
                return paths
        n+=1
        if count == M-1 and n >10:
            print paths
            return paths
    return paths
print "paths"
print build_paths(4,5)
print "----"
print build_matrix_from_graph(build_paths(4,5),5)




if __name__ == "__main__":
    #f = open("B-practice.in",'r')
    #f = open("B-large.in",'r')
    f = open("B-small-attempt0.in",'r')
    test_cases = int(f.readline())
    #out = open("results_B_p_0.txt",'w')
    out = open("results_B_s_0.txt",'w')
    #out = open("results_B_l_0.txt",'w')
    answer = ""

    print test_cases
    for index in range(test_cases):
        print "\nTest case #%d"%index
        B,M = [int(x) for x in f.readline().strip("\n").split(" ")]
        print B,M
        answer = ""
        print int(math.exp(1)*math.factorial(B-2))

        if B == 2:
            if M == 1:
                answer += "POSSIBLE\n"
                answer += "01\n00"
            else:
                answer += "IMPOSSIBLE"
        elif B == 3:
                if M > 2:
                    answer +="IMPOSSIBLE"
                else:
                    answer +="POSSIBLE\n"
                    if M == 2:
                        answer+=build_matrix_from_graph([(1,3),(1,2),(2,3)],B)
                    else:
                        answer+=build_matrix_from_graph([(1,3)],B)
        elif B>3:
            if M > int(math.exp(1)*math.factorial(B-2)) : #change condition
                answer +="IMPOSSIBLE\n"
            else:
                answer +="POSSIBLE\n"
                answer+= build_matrix_from_graph(build_paths(M,B),B)



        output = output_format(answer,index)
        print output
        out.write(output)


