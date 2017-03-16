

if __name__ == '__main__':
    case_count = input()
    for x in xrange(0, case_count):
        E, R, N = map(int, raw_input().split(' '))
        acts = map(int, raw_input().split(' '))

        prios = [n for n in xrange(0, len(acts))]
        prios.sort(key=lambda x: -acts[x])
        
        energy = [None] * len(acts)

        def mark(index):
            marked = energy[index]
            if marked is None:
                e = E
            else:
                e = E - marked
            energy[index] = E
            i = index
            ie = e
            while i > 0:
                i -= 1
                smarked = energy[i]
                if smarked is None:
                    ie -= R
                if ie <= 0:
                    break
                if smarked is None:
                    energy[i] = ie
                else:
                    energy[i] += ie
            i = index
            ie = e
            while i < len(acts) - 1:
                i += 1
                smarked = energy[i]
                if smarked is None:
                    ie -= R
                if ie <= 0:
                    break
                if smarked is None:
                    energy[i] = ie
                else:
                    energy[i] += ie
            return e

        score = 0
        for index in prios:
            value = acts[index]
            e = mark(index)
            score += value * e

        print 'Case #%d:' % (x + 1), score
