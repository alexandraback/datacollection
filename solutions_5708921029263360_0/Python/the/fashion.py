#input_file = "test.in"
input_file = "C-small-attempt4.in"
output_file = "result.out"

with open(input_file) as in_file, open(output_file, 'w') as out_file:
    testcases = int(in_file.readline())
    for i in range(1, testcases + 1):
        help = [int(x) for x in in_file.readline().split()]

        J = int(help[0])
        P = int(help[1])
        S = int(help[2])

        K = int(help[3])

        jp = {}
        js = {}
        ps = {}
        res = []
        helpres = []
        count = 0
        s = 0
        for j in range(1, J+1):
            for p in range(1, P+1):
                k = 0
                while k < min(K, S):
                    help = (s + k) % S + 1
                    if (j, p) not in jp:
                        jp[(j, p)] = 0
                    if (j, help) not in js:
                        js[(j, help)] = 0
                    if (p, help) not in ps:
                        ps[(p, help)] = 0
                    if jp[(j, p)] < K and js[(j, help)] < K and ps[(p, help)] < K:
                        helpres.append([j, p, help])
                        jp[(j, p)] += 1
                        js[(j, help)] += 1
                        ps[(p, help)] += 1
                    k += 1
                    # else:
                    #     print('error')
                    #res.append([j, p, (s + k) % S + 1])

                count += 1
                s += 1
                if count == S:
                    count = 0
                    s = (s + 1) % S

        res = helpres
        # if not helpres == res:
        #     print('error helpres')

        out_file.write('Case #{}: {}\n'.format(i, len(res)))
        for l in res:
            out_file.write('{} {} {}\n'.format(l[0], l[1], l[2]))
