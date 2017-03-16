def slide(B, M):
    if M > 2**(B-2): return "IMPOSSIBLE"
    el = ['POSSIBLE']
    if M == 2**(B-2):
        el.append('0' + (B-1)*'1')
    else:
        x = bin(M)[2:]
        el.append('0'*(B-len(x)-1) + x + '0')
    for line in range(2, B+1):
        el.append('0'*line + '1'*(B-line))
    return '\n'.join(el)

def main():
    cases = int(raw_input())
    for case in range(1, cases+1):
        B, M = map(int, raw_input().split())
        print "Case #%i:" %case, slide(B, M)

if __name__ == '__main__':
    main()
