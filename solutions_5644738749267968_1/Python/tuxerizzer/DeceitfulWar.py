if __name__ == '__main__':
    for casenum in range(input()):
        blocks = input()

        naomi = sorted([float(i) for i in raw_input().split()])
        ken = sorted([float(i) for i in raw_input().split()])

        naomi_d = naomi[:]
        ken_d = ken[:]

        score = 0
        for i in range(len(naomi)):
            np = naomi.pop()

            for k in ken:
                if k > np:
                    ken.remove(k)
                    break
            else:
                ken = ken[1:]
                score += 1

        score_d = 0
        for i in range(len(ken_d)):
            kp = ken_d.pop()

            for n in naomi_d:
                if n > kp:
                    naomi_d.remove(n)
                    score_d += 1
                    break
            else:
                naomi_d = naomi_d[1:]

        print 'Case #%d: %d %d' % (casenum + 1, score_d, score)
