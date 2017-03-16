import sys

SOLNS = {():0, (1):1}

def solve(pancakes):
    key = tuple(pancakes)
    if key in SOLNS:
        return SOLNS[key]

    max_stack = pancakes.pop(0)

    if max_stack >= 4:
        start = max_stack//2 if max_stack%2==0 else max_stack//2+1
        splits = [(i, max_stack-i) for i in range(start, max_stack-1)]
        scenarios = [insert_stacks(split, pancakes.copy()) for split in splits]
        soln = min(max_stack, 1 + min([solve(scenario) for scenario in scenarios]))
    else:
        soln = max_stack

    SOLNS[key] = soln
    return soln


def insert_stack(stack, pancakes):
    for (i, s) in enumerate(pancakes):
        if stack >= s:
            pancakes.insert(i, stack)
            return pancakes

    pancakes.append(stack)
    return pancakes

def insert_stacks(stacks, pancakes):
    (stack1, stack2) = stacks
    pancakes = insert_stack(stack2, pancakes)
    pancakes = insert_stack(stack1, pancakes)
    return pancakes

def possible_scenarios(splits, pancakes):
    return 


if __name__ == "__main__":

    T = int(sys.stdin.readline())

    for case in range(T):

        num_diners = int(sys.stdin.readline())

        pancakes = sorted([int(X) for X in sys.stdin.readline().split()], reverse=True)
        # trivial solution based on input
        if pancakes[0] <= 3:
            soln = pancakes[0]
        else:
            #do not consider when there is only 1 pancake
            pancakes = [p for p in pancakes if p > 1]
            soln = solve(pancakes)

        print("Case #", case+1, ": ", soln, sep="")