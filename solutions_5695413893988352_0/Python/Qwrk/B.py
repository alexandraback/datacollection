
def match(pattern, y):
    for p, j in zip(pattern, y):
        if p == '?':
            continue
        if p != j:
            return False
    return True


t = int(input())
for case in range(1, t + 1):
    c, j = input().split()
    mc, mj = 0, 0
    b = 10000
    for i in range(10**len(c)):
        if match(c, str(i).zfill(len(c))):
            for k in range(10**len(c)):
                if match(j, str(k).zfill(len(c))):
                    if b > abs(i - k):
                        b = abs(i - k)
                        mc, mj = i, k
    print('Case #%d: %s %s' % (case, str(mc).zfill(len(c)), str(mj).zfill(len(c))))





# if __name__ == "__main__":
#     t = int(input())
#     for case in range(1, t + 1):
#         c, j = input().split()
#         rc, rj = [i for i in c], [i for i in j]
#         b = 0
#         for i in range(len(c)):
#             if b == 0:
#                 if rc[i] == rj[i] == '?':
#                     rc[i] = rj[i] = '0'
#                 elif rc[i] == '?' and rj[i] != '?':
#                     rc[i] = rj[i]
#                 elif rc[i] != '?' and rj[i] == '?':
#                     rj[i] = rc[i]
#                 elif rc[i] > rj[i]:
#                     b = 1
#                 elif rc[i] < rj[i]:
#                     b = -1
#             elif b == 1: # c > j
#                 if rc[i] == '?':
#                     rc[i] = '0'
#                 if rj[i] == '?':
#                     rj[i] = '9'
#             else: # j > c
#                 if rc[i] == '?':
#                     rc[i] = '9'
#                 if rj[i] == '?':
#                     rj[i] = '0'
#         print('Case #%d: %s %s' % (case, ''.join(rc), ''.join(rj)))



