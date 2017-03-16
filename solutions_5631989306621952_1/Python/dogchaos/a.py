

class Template:
    def process(self, fin, fout):
        ans = ''
        S = fin.readline().strip()
#         print S
        for x in S:
            if ans == '':
                ans = x
            else:
                if x >= ans[0]:
                    ans = x + ans
                else:
                    ans = ans + x

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
