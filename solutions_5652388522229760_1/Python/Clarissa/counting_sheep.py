#Let's help some sheep fall asleep :)

import fileinput

def find_minimum_sleep_number(starting_N):
    """
    Given a starting value N, finds the multiple k*N such that all digits are
    represented among {i*N}_i=1^k
    
    param: starting_N, the starting value N for counting
    return: either 'INSOMNIA' if impossible or the minimum value counted to.
    """
    
    if starting_N == 0:
        return 'INSOMNIA'
    else:
        all_digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
        multiplier_i = 0
        
        while len(all_digits) > 0:
            multiplier_i += 1
            current_value = multiplier_i*starting_N
            #print(current_value)
            stripped_value = current_value
            
            while stripped_value >= 1:
                current_digit = stripped_value%10
            
                all_digits.discard(current_digit)
                
                # Remove last digit from value
                stripped_value -= current_digit
                stripped_value //= 10                
                
        
        return current_value

"""
# This turned out to be unnecessary because it is quick to compute for the given range.
def preprocess():
    for iteration_N in range(int(1e6)+1):
        print(find_minimum_sleep_number(iteration_N))
"""

def main():
    firstLine = True
    case = 1
    for line in fileinput.input():
        if firstLine:
            firstLine = False
            continue

        starting_N = int(line.strip())
        print('CASE #' + str(case) + ': ', end="")
        print(find_minimum_sleep_number(starting_N))
        case += 1

if __name__ == '__main__':
    main()
