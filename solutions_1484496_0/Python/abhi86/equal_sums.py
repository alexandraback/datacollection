import itertools

with open('C:\\Users\\abhijit\\Documents\\C-small-attempt0.in') as f1:
    with open('C:\\Users\\abhijit\\Documents\\output.txt', 'w') as f2:
            T = int(f1.readline().strip())
            for i in range(T):
                f2.write('Case #'+ str((i+1)) + ':\n')
                toks = f1.readline().split()
                nums = [int(n) for n in toks[1:]]
                subsets = []
                for l in range(len(nums)):
                    subsets += itertools.combinations(nums, l + 1)

                sums_dict = {}
                possible = False
                for subset in subsets:
                    sum_val = sum(subset)
                    if sum_val in sums_dict and sums_dict[sum_val] != subset:
                        for num in sums_dict[sum(subset)]:
                            f2.write(str(num) + ' ')
                        f2.write('\n')
                        for num in subset:
                            f2.write(str(num) + ' ')
                        f2.write('\n')
                        possible = True
                        break
                    else:
                        sums_dict[sum(subset)] = subset

                if not possible:
                    f2.write('Impossible\n')
                    
