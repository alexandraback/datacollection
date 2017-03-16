import sys

def solve(t):
    dic = dict()
    for i in xrange(ord("A"), ord("Z")+1):
        dic[chr(i)] = 0
    for i in t:
        dic[i] += 1
    ans = [dic["Z"], 0, dic["W"], 0, 0, 0, dic["X"], 0, dic["G"], 0]
    dic["S"] -= ans[6]
    ans[7] = dic["S"]
    #0, 2, 6, 7, 8
    dic["T"] -= ans[2]+ans[8]
    ans[3] = dic["T"]
    dic["R"] -= ans[0]+ans[3]
    ans[4] = dic["R"]
    dic["F"] -= ans[4]
    ans[5] = dic["F"]
    #print ans[5], ans[8]
    #print dic["I"]
    dic["I"] -= ans[5]+ans[8]+ans[6]
    #print dic["I"]
    ans[9] = dic["I"]
    dic["N"] -= ans[9]*2+ans[7]
    ans[1] = dic["N"]
    string = ""
    for i in xrange(10):
        string += ("%d" % i)*ans[i]
    return string

input_filename = sys.argv[1]
#input_filename = "in.txt" #"A-small-attempt0(1).in"#

with open(input_filename, "r") as infile:
    with open("out.txt", "w") as outfile:
        tnum = int(infile.readline())
        for t in xrange(tnum):
            test = infile.readline().strip()
            ans = solve(test)
            outfile.write("Case #%d: %s\n" % (t+1, ans))
            print (t+1, ans)
        