import sys

with open(sys.argv[1]) as f:
    lines = f.readlines()

def choose_best(options):
    best_diff = None
    best_1 = None
    best_2 = None
    cbest_1 = None
    cbest_2 = None
    for op in options:
        if op is None:
            continue
        num1 = op[0]+op[2][0]
        num2 = op[1]+op[2][1]
        inum1 = int(num1,10)
        inum2 = int(num2,10)
        abs_diff = abs(inum1-inum2)
        if best_diff is None:
            best_diff = abs_diff+1
        if abs_diff < best_diff or (abs_diff == best_diff and inum1 < best_1) or(abs_diff == best_diff and inum1 == best_1 and inum2 < best_2):
            best_diff = abs_diff
            best_1 = inum1
            best_2 = inum2
            cbest_1 = num1
            cbest_2 = num2
    return cbest_1, cbest_2

memoized = dict()

def solve(s1,s2,bigger=None):
    if (s1,s2,bigger) in memoized:
        return memoized[(s1,s2,bigger)]
    out1 = ""
    out2 = ""
    if bigger is None:
        bigger = "None"
    for n,(i,j) in enumerate(zip(s1,s2)):
        if i == "?" and j == "?":
            if bigger == "None":
                option1 = ("0","0",solve(s1[n+1:], s2[n+1:], bigger="None"))
                option2 = ("0","1",solve(s1[n+1:], s2[n+1:], bigger="Second"))
                option3 = ("1","0",solve(s1[n+1:], s2[n+1:], bigger="First"))
                #print "ops:", [option1,option2,option3]
                best_option = choose_best([option1,option2,option3])
                #print "best:", best_option
                out1 = out1 + best_option[0]
                out2 = out2 + best_option[1]
                memoized[(s1,s2,bigger)] = (out1,out2)
                return out1, out2

            elif bigger == "First":
                out1 += "0"
                out2 += "9"
            elif bigger == "Second":
                out1 += "9"
                out2 += "0"
            else:
                assert False
        elif i == "?" and j != "?":
            if bigger == "First":
                out1 += "0"
                out2 += j
            elif bigger == "Second":
                out1 += "9"
                out2 += j
            elif bigger == "None":
                option1 = (j,j,solve(s1[n+1:], s2[n+1:], bigger="None"))
                option2 = None
                if j != "0":
                    option2 = (chr(ord(j)-1),j,solve(s1[n+1:], s2[n+1:], bigger="Second"))
                option3 = None
                if j != "9":
                    option3 = (chr(ord(j)+1),j,solve(s1[n+1:], s2[n+1:], bigger="First"))
                best_option = choose_best([option1,option2,option3])
                out1 = out1 + best_option[0]
                out2 = out2 + best_option[1]
                memoized[(s1,s2,bigger)] = (out1,out2)
                return out1, out2
            else:
                raise Exception("wtf")
        elif i != "?" and j == "?":
            if bigger == "First":
                out1 += i
                out2 += "9"
            elif bigger == "Second":
                out1 += i
                out2 += "0"
            elif bigger == "None":
                option1 = (i,i,solve(s1[n+1:], s2[n+1:], bigger="None"))
                option2 = None
                if i != "0":
                    option2 = (i,chr(ord(i)-1),solve(s1[n+1:], s2[n+1:], bigger="First"))
                option3 = None
                if i != "9":
                    option3 = (i,chr(ord(i)+1),solve(s1[n+1:], s2[n+1:], bigger="Second"))
                best_option = choose_best([option1,option2,option3])
                out1 = out1 + best_option[0]
                out2 = out2 + best_option[1]
                memoized[(s1,s2,bigger)] = (out1,out2)
                return out1, out2
            else:
                raise Exception("wtf")
        elif i != "?" and j != "?":
            if bigger == "None":
                if (int(i,10) > int(j,10)):
                    bigger = "First"
                elif (int(i,10) < int(j,10)):
                    bigger = "Second"
                elif (int(i,10) == int(j,10)):
                    bigger = "None"
                else:
                    raise Exception("wtf")
            assert bigger in ("None", "First", "Second")
            out1 += i
            out2 += j
        else:
            raise Exception("wtf")
    memoized[(s1,s2,bigger)] = (out1,out2)
    return out1, out2
T = int(lines[0],10)
for i, l in enumerate(lines[1:]):
    s1, s2 = l.strip().split(" ")
    out1, out2 = solve(s1,s2)
    print ("Case #%d:" % (i+1)), out1, out2
    assert len(out1) == len(s1)

        

