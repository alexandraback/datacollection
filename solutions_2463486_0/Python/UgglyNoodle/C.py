import math

f_in = open('C-small-attempt0.in', 'r')
f_out = open('C-small-attempt0.out', 'w')

num_cases = int(f_in.readline().strip())

for idx_case in range(num_cases):
    A_B_list = f_in.readline().strip().split()
    num_digits_A = len(A_B_list[0])
    num_digits_B = len(A_B_list[1])
    A = int(A_B_list[0])
    B = int(A_B_list[1])
    
    num_fair_and_square = 0
    
    # n is the smaller palindrome, n_sq is the larger palindrome
    for num_digits_n in range((num_digits_A + 1) / 2, (num_digits_B + 3) / 2):
        num_digits_m = (num_digits_n + 1) / 2
        for m in range(10 ** (num_digits_m - 1), 10 ** num_digits_m):
            if num_digits_n % 2 == 0:
                n = int(str(m) + str(m)[::-1])
            else:
                n = int(str(m) + str(m)[-2::-1])
            n_sq = n * n
            if n_sq >= A and n_sq <= B and str(n_sq) == str(n_sq)[::-1]:
                num_fair_and_square += 1
    
    f_out.write('Case #{}: {}\n'.format(idx_case+1, num_fair_and_square))

f_in.close()
f_out.close()