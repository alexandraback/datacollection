# Let's make some happy pancakes!
import fileinput

def calculate_minimum_flips_to_happy(pancake_stack):
    """
    Determines the minimum number of flips needed to get a string of +s and -s
    to a string of all +s, where any flips must be done for all characters 1:k
    
    param: pancake_stack, a stack of pancakes represented as a string of + and -
    return: the minimum number of flips needed to get to all +
    """
    count = 0
    first_pancake_streak = True
    current_streak_mood = None
    HAPPY = '+'
    SAD = '-'
    
    for pancake in pancake_stack:
        # If we're in the same streak, just keep going
        if current_streak_mood == pancake:
            continue
        
        # Otherwise we just changed polarity
        else:
            current_streak_mood = pancake
            
            # If we found a streak of sad pancakes, we have to fix them!
            if current_streak_mood == SAD:
                # It's easier to fix pancakes at the beginning.
                if first_pancake_streak:
                    count += 1
                else:
                    count += 2
            
            first_pancake_streak = False
    
    return count

def main():
    firstLine = True
    case = 1
    for line in fileinput.input():
        if firstLine:
            firstLine = False
            continue

        pancake_stack = line.strip()
        print('CASE #' + str(case) + ': ', end='')
        print(calculate_minimum_flips_to_happy(pancake_stack))
        case += 1


if __name__ == "__main__":
    main()
