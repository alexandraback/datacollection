for case in range(int(input())):
    smax, aud = input().strip().split()
    count, invite = 0, 0
    for i in range(int(smax) + 1):
        if aud[i] != '0' and count < i:
            invite += (i - count)
            count += invite
        count += int(aud[i])
    ans = invite
    print('Case #{}: {}'.format(case + 1, ans))