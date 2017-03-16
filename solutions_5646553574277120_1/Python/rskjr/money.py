# Google Code Jam 2015

def currencies(c, D, v):
    D = list(D)
    added = []
    if not D.count(1):
        added.append(1)
        D.insert(0, 1)
    i = 1
    while True:
        if i < len(D):
            currMax = 0
            for j in range(i):
                currMax += c * D[j]
            if currMax < D[i] - 1:
                D.insert(i, currMax + 1)
                added.append(currMax + 1)
            i += 1
        else:
            total_possible = sum([c * j for j in D])
            if total_possible < v:
                D.append(total_possible + 1)
                added.append(total_possible + 1)
            else:
                break

    return len(added)



def unit_tests():
    assert currencies(1, (1,2), 3) == 0
    assert currencies(1, (1,2, 5), 6) == 1
    assert currencies(2, (3,), 3) == 1
    assert currencies(1, (1, 5, 10, 25, 50, 100), 100) == 3
    assert currencies(1, (1,5), 13) == 3
    assert currencies(1, (1,5), 27) == 4
    print "Unit tests passed."

def generate_result(fname):
    assert type(fname) == str
    s = ""
    lines = open(fname).readlines()
    casenum = 1
    i = 1
    while i < len(lines):
        strs = []
        print lines
        (c, d, v) = [int(j) for j in lines[i].strip().split(' ')]
        i += 1
        ds = [int(j) for j in lines[i].strip().split(' ')]
        ans = currencies(c, ds, v)
        s += "Case #{}: {}\n".format(casenum, ans)
        casenum += 1
        i += 1
    print s
    return s

def test_e2e(input_fname, correctfname):
    f = open(correctfname)
    myans = generate_result(input_fname)
    key = "".join(f.readlines())
    assert myans == key

if __name__ == "__main__":
    infilename = "C-large.in"
    unit_tests()
    test_e2e("testin.txt", "testout.txt.gold")
    downloadsdirectory = "/Users/robertkarl/Downloads/"
    answer = generate_result(downloadsdirectory + infilename)
    outfile = open(downloadsdirectory + infilename + "ans.txt", 'w')
    outfile.write(answer)
    outfile.close()

