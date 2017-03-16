cases = raw_input()
for case in range(int(cases)):
    temp = raw_input()
    print "Case #" + str(case + 1) + ": " + " ".join(map(lambda i: str(i + 1), range(int(temp.split()[0]))))