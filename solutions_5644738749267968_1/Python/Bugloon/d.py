import sys

def deceitful_war(n_blocks, k_blocks):
    
    num_blocks = len(n_blocks)

    k_index = 0

    n_score = 0

    for n_index in range(num_blocks):
        if n_blocks[n_index] > k_blocks[k_index]:
            n_score += 1
            k_index += 1

    return n_score

def war(n_blocks, k_blocks):

    num_blocks = len(n_blocks)

    k_index = num_blocks - 1

    n_score = 0

    for n_index in range(num_blocks - 1, -1, -1):
        if n_blocks[n_index] > k_blocks[k_index]:
            n_score += 1
        else:
            k_index -= 1

    return n_score

if __name__ == "__main__":

    testcases = int(sys.stdin.readline())

    for case in range(1, testcases+1):
        num_blocks = int(sys.stdin.readline())
        naomi_blocks = map(float, sys.stdin.readline().split())
        naomi_blocks.sort()
        ken_blocks = map(float, sys.stdin.readline().split())
        ken_blocks.sort()
        
        print("Case #{}: {} {}".format(
              case,
              deceitful_war(naomi_blocks, ken_blocks), 
              war(naomi_blocks, ken_blocks)))
        
