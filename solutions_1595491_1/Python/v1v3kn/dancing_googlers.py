"""
Dancing Googlers - Problem 2
"""


def maxk(n, surprising, threshold, *scores):
    scores = sorted(scores, key=lambda x: -x)
    best_scores = []
    for i, score in enumerate(scores):
        best = (score // 3) + 1 if score % 3 else score // 3 
        if surprising > 0 and best < threshold and score % 3 in [0, 2]:
            # possible cases -> 3n - 3 (rem 0) ; 3n-4 (rem 2); 3n - 2 (rem 1)
            best += 1
            surprising -= 1

        if not score:
            best = 0
            
        best_scores.append(best)
    return sum(1 for x in best_scores if x >= threshold)


def main():
    import sys
    f = open(sys.argv[1])
    out = open(sys.argv[2], 'w')
    index = 1
    lines = []
    f.next()
    while True:
        try:
            case = map(int, f.next().strip().split())
            lines.append("Case #%d: %s" % (index, maxk(*case)))
            index += 1
        except StopIteration:
            break
    out.write('\n'.join(lines))
    out.close()

if __name__ == '__main__':
    main()