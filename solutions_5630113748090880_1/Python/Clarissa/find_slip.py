
import sys

def find_missing_strip(all_strips):
    # Finds the missing strips by counting values: odd is missing.
    MAX_HEIGHT = 2500
    missing_heights = []
    
    # Counting: height_counts[0] = occurrences of the height 1
    height_counts = [0]*MAX_HEIGHT
    
    for strip in all_strips:
        for height in strip:
            height_counts[height-1] += 1
    
    for offset_height in range(MAX_HEIGHT):
        if height_counts[offset_height]%2 == 1:
            missing_heights.append(offset_height + 1)
    
    missing_heights.sort()
    return missing_heights

def main():
    firstLine = True
    case = 1
    cases = int(sys.stdin.readline().strip())
    
    for i in range(cases):
        number_rows = int(sys.stdin.readline().strip())
        
        strips_I_have = []
        for i in range(2*number_rows-1):
            heights = [int(number) for number in sys.stdin.readline().strip().split()]
            strips_I_have.append(heights)
        
        print('Case #' + str(case) + ': ', end="")
        missing_heights = find_missing_strip(strips_I_have)
        for height in missing_heights:
            print(height, end=' ')
        print()
        case += 1

if __name__ == '__main__':
    main()
