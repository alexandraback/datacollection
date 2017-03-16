import itertools

if __name__ == "__main__":
    T = int(input())
    for i in range(1,T+1):
        C,J = input().split(" ")
        Cq = C.count("?")
        Jq = J.count("?")
        m = 999
        mC = C.replace("?","9")
        mJ = J.replace("?","9")
        for Csub_sort in itertools.combinations_with_replacement(range(10), Cq):
            for Csub in itertools.permutations(Csub_sort):
                for Jsub_sort in itertools.combinations_with_replacement(range(10), Jq):
                    for Jsub in itertools.permutations(Jsub_sort):

                        Ci = 0
                        Ji = 0
                        Ctest = ""
                        Jtest = ""
                        for l in C:
                            if l == "?":
                                Ctest += str(Csub[Ci])
                                Ci += 1
                            else:
                                Ctest += l
                        for l in J:
                            if l == "?":
                                Jtest += str(Jsub[Ji])
                                Ji += 1
                            else:
                                Jtest += l
                        Jint = int(Jtest)
                        Cint = int(Ctest)
                        diff = abs(Jint - Cint)
                        # print(Ctest, Jtest, diff, m)
                        if diff < m or (diff == m and Cint < int(mC)) or \
                                (diff == m and Cint == int(mC) and Jint < int(mJ)):
                            m = diff
                            mC = Ctest
                            mJ = Jtest
        print("Case #%i: %s %s" % (i,mC,mJ))
