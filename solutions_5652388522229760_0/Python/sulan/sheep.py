def print_result (case_num,result):
    print('Case #{}: {}'.format(case_num,result))

T = int(input())
for i in range(T):
    case_num = i+1
    N = int(input())
    seen_digits = set()
    if N == 0:
        print_result(case_num,'INSOMNIA')
        continue
    j = 0
    num = -1
    while len(seen_digits) != 10:
        j += 1
        num = str(N*j)
        seen_digits |= set(num)
    print_result(case_num,num)

        
