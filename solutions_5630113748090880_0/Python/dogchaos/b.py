

class Template:
    def process(self, fin, fout):
        max_l = 2501
        ans_list = []
        N = int(fin.readline().strip())
        H = [False for _ in range(max_l)]
        M = [[] for _ in range(2 * N - 1)]
        for i in range(2 * N - 1):
            M[i] = [int(x) for x in fin.readline().strip().split()]

        for i in range(2 * N - 1):
            for j in range(N):
                l = M[i][j]
                if not H[l]:
                    H[l] = True
                else:
                    H[l] = False

        for i in range(max_l):
            if H[i]:
                ans_list.append(str(i))

        ans = ' '.join(ans_list)

        print str(ans)
        fout.write(str(ans))

    def solve(self):
        # fin = open('../boomerang_constellations.txt', 'r')
        # fin = open('../test', 'r')
        fin = open('../in.in', 'r')
        fout = open('../out', 'w')
        times = int(fin.readline())
        for i in range(times):
            fout.write("Case #%d: " % (i + 1))
            self.process(fin, fout)
            fout.write("\n")
        fin.close()
        fout.close()

    def make_test(self):
        fout = open('../test', 'w')
        fout.write('1\n2000\n')
        for i in range(2000):
            fout.write('%d %d\n' % ((-1000 + i), 1000 - i))
        fout.close()


def nC2(n):
    return int(n * (n - 1) / 2)


def line(a, b):
    return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2)


if __name__ == '__main__':
    t = Template()
    t.solve()
