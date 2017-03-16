# Google Code Jam 2015

def brattle(r, c, w):
    count = 0
    for i in range(r - 1):
        count += c / w
    count += (c/w - 1) + w + (1 if (c % w) else 0)
    return count

def unit_tests():
    assert brattle(1, 4, 2) == 3
    assert brattle(1, 7, 7) == 7
    assert brattle(2, 5, 1) == 10
    assert brattle(1, 9, 6) == 7
    assert brattle(1, 5, 2) == 4
    assert brattle(1, 10, 4) == 6
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
        (r, c, w) = [int(j) for j in lines[i].strip().split(' ')]
        ans = brattle(r, c, w)
        s += "Case #{}: {}\n".format(casenum, 
            ans if ans > -1 else "Fegla Won")
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
    infilename = "A-small-attempt1.in"
    unit_tests()
    test_e2e("testin.txt", "testout.txt.gold")
    downloadsdirectory = "/Users/robertkarl/Downloads/"
    answer = generate_result(downloadsdirectory + infilename)
    outfile = open(downloadsdirectory + infilename + "ans.txt", 'w')
    outfile.write(answer)
    outfile.close()

