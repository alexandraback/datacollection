def fractile(K, C, S):
    if K > S*C: return "IMPOSSIBLE"
    el = []
    for first in range(0, K, C):
        x = 1
        for gen, bit in enumerate(range(first, min(first+C, K))):
            x += (K**gen)*bit
        el.append(str(x))
    return ' '.join(el)

def main():
    cases = int(raw_input())
    for case in range(1, cases+1):
        K, C, S = map(int, raw_input().split())
        print "Case #%i:" %case, fractile(K, C, S)

if __name__ == '__main__':
   main()
