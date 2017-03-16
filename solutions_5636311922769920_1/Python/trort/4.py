def solver(k, c, s):
    if s * c < k:
        return 'IMPOSSIBLE'
    else:
        check_list = range(1, k+1, c)
        if c > 1:
            for level in range(1, c):
                #print check_list
                mix_list = range(level+1, k+1, c)
                new_check_list = list(check_list)
                for i in range(len(mix_list)):
                    new_check_list[i] = (mix_list[i]-1)*(k**level) + check_list[i]
                check_list = list(new_check_list)
        return ' '.join([str(x) for x in check_list])

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  K, C, S = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
  ans = solver(K,C,S)
  print "Case #{}: {}".format(i, ans)