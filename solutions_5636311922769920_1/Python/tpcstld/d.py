
def convert(start, end, base):
    total = end - start
    answer = 0
    for x in xrange(start, end + 1):
        answer = answer + x * (base ** total)
        total = total - 1

    assert total == -1
    return answer

def main(data):
    K, C, S = data.split()
    K = int(K)
    C = int(C)
    S = int(S)

    if K / C > S:
        return "IMPOSSIBLE"

    answer = []
    start = 0
    while start < K:
        end = min(K - 1, start + C - 1)
        result = convert(start, end, K) + 1
        answer.append(str(result))
        start = start + C

    assert len(set(answer)) == len(answer)
    return " ".join(answer)

T = int(raw_input())
for x in xrange(T):
    print "Case #" + str(x + 1) + ": " + main(raw_input())
