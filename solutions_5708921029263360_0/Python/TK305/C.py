if __name__ == "__main__":
    with open("C-small-attempt0.in", 'r') as inputf:
        outputf=open("C-small.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline().rstrip('\n')
            temp = line. split(' ')
            J = int(temp[0])
            P = int(temp[1])
            S = int(temp[2])
            K = int(temp[3])
            js = {}
            ps = {}
            jp = {}
            tot = 0
            answer = []

            for j in range(1, 1+J):
                for p in range(1, 1+P):
                    for s in range(1, 1+S):
                        pair = str(j) + " " + str(p) + " " + str(s)
                        js_pair = str(j) + str(s)
                        ps_pair = str(p) + str(s)
                        jp_pair = str(j) + str(p)
                        possible = True

                        if js_pair in js and js[js_pair] >= K:
                            possible = False
                        if ps_pair in ps and ps[ps_pair] >= K:
                            possible = False
                        if jp_pair in jp and jp[jp_pair] >= K:
                            possible = False
                        if js_pair not in js:
                            js[js_pair] = 0
                        if ps_pair not in ps:
                            ps[ps_pair] = 0
                        if jp_pair not in jp:
                            jp[jp_pair] = 0

                        if possible:
                            tot += 1
                            answer.append(pair)
                            js[js_pair] += 1
                            ps[ps_pair] += 1
                            jp[jp_pair] += 1

            answer_str = "\n".join(answer)
            result = "Case #{0}: {1}\n{2}".format(i, tot, answer_str)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")