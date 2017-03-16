import sys

# sys.stdin = open('b.in', 'r')
sys.stdin = open('B-small-attempt1.in', 'r')
sys.stdout = open('B-small-attempt1.out', 'w')

for t in range(int(input())):

    n = int(input())

    a = sorted(map(int, input().split()), reverse=True)

    ans = deadline = max(a)

    # 直接枚举结果，当然可以用二分做到更快
    for deadline in range(2, ans):
        # print('D: %d' % deadline)
        success = False
        for special in range(1, deadline - 1):
            block = deadline - special
            # print('  B: %d' % block)
            # 按照 block 来分要几步
            acc = sum([(x - 1) // block for x in a])
            if acc <= special:
                success = True
                # print(block)
                break
        if success:
            # print('success')
            ans = deadline
            break

    print('Case #%d: %s' % (
        t + 1,
        ans
    ))

sys.stdin.close()
sys.stdout.close()