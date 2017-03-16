import fileinput

def solve(c_s,j_s):
    c_res = []
    j_res = []
    leader = 0 # 0 - tie, 1 - c is leading, -1 - j is leading
    for i in range(len(c_s)):
        c_c = c_s[i]
        j_c = j_s[i]
        if i+1 < len(c_s):
            j_n = j_s[i+1]
            c_n = c_s[i+1]
        else:
            j_n = "0"
            c_n = "0"
        # c:0?0 j:0?6 -> 10,06. Delta 4
        # c:0?0 j:0?5 -> 00,05. Delta 5 
        # c:0?1 j:0?5 -> 01,05. Delta 4
        # c:0?6 j:0?0 -> 06,10. Delta 4
        if c_c == "?":
            if leader == 0:
                if j_c != "?":
                    if j_n != "?" and c_n != "?" and j_n != c_n:
                        if int(c_n) < int(j_n)-5 and int(j_c) < 9:
                            #print "c_c1"
                            c_c = str(int(j_c) + 1)
                        elif (int(j_n) <= int(c_n)-5) and int(j_c) > 0:
                            c_c = str(int(j_c) - 1)
                    if j_n == "?" and c_n != "?":
                        if (5 <= int(c_n)) and int(j_c) > 0:
                            c_c = str(int(j_c) - 1)
                    if c_c == "?":
                        #print "c_c2"
                        c_c = j_c
                else:
                    if j_n != "?" and c_n != "?" and j_n != c_n:
                        if int(c_n) < int(j_n)-5: 
                            #print "c_c3",c_n,j_n
                            c_c = "1"
                    if c_c == "?":
                        #print "c_c4"
                        c_c = "0"
            elif leader == -1:
                # C is leading, minimize C's score
                #print "c_c5"
                c_c = "0"
            elif leader == 1:
                #J is leading, maximize C's score
                #print "c_c6"
                c_c = "9"
        if j_c == "?":
            if leader == 0:
                if c_c != "?":
                    if c_n != "?" and j_n != "?" and j_n != c_n:
                        #print "XX",c_c,j_c,c_n,j_n
                        if int(j_n) < int(c_n)-5 and (int(c_c) < 9): 
                            #print "j_c1"
                            j_c = str(int(c_c) + 1)
                        elif (int(c_n) < int(j_n)-5) and int(c_c) > 0:
                            j_c = str(int(c_c) - 1)
                    if c_n == "?" and j_n != "?":
                        if int(j_n) == 9 and int(c_c) < 9:
                            j_c = str(int(c_c) + 1)
                    if j_c == "?":
                        #print "j_c2"
                        j_c = c_c
                else:
                    if j_n != "?" and c_n != "?" and j_n != c_n:
                        if int(j_n) < int(c_n)-5: 
                            #print "j_c3"
                            j_c = "1"
                    if j_c == "?":
                        #print "j_c4"
                        j_c = "0"
            elif leader == 1:
                # J is leading, minimize J's score
                #print "j_c5"
                j_c = "0"
            elif leader == -1:
                #C is leading, maximize J's score
                #print "j_c6"
                j_c = "9"
        assert j_c != "?" and c_c != "?"
        c_res.append(c_c)
        j_res.append(j_c)
        if leader == 0 and j_c != c_c:
            if j_c < c_c:
                leader = 1
            else:
                leader = 1
    return "".join(c_res)+" "+"".join(j_res)

def check_match(s,p):
    for c_1,c_2 in zip(s,p):
        if c_1 != c_2 and c_2 != "?":
            #print "Mismatch:",c_1,c_2
            return False
    return True

def brute_force(c_s,j_s):
    best_sol = (10000,(0,0),"","")
    for c_i in range(10**len(c_s)):
        c_t = ("%0"+str(len(c_s))+"d")%c_i
        #print "Test",c_t,"against",c_s
        if not check_match(c_t,c_s):
            continue
        for j_i in range(10**len(c_s)):
            j_t = ("%0"+str(len(c_s))+"d")%j_i
            #print "Test2",j_t,"against",j_s
            if not check_match(j_t,j_s):
                continue
            sol = (abs(c_i-j_i),(c_i,j_i),c_t,j_t)
            #print "sol",sol
            if sol < best_sol:
                best_sol = sol
    return best_sol[2]+" "+best_sol[3]

def main():
    it = fileinput.input()
    cnt = it.next()
    for i,l in enumerate(it,1):
        c_s,j_s = l.split()
        print "Case #%d: %s" % (i,brute_force(c_s,j_s))

if __name__ == "__main__":
    main()
        
