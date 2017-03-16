# Let's get our grad students gold hunting!

import fileinput
import math

def pick_tiles_simple(number_tiles, complexity):
    """
    Assumes I have at least as many students as tiles and determines which
    tiles the students should look at to see if the fractile has gold.
    
    param: number_tiles, the number of tiles in the original fractile
    param: complexity, the number of repetitions of the original fractile
           (with pattern based on lead-gold rules)
    return: a list of positions of tiles to clean off to look for gold
    """
    
    tile_indices = [i*number_tiles**(complexity-1) + 1
                    for i in range(number_tiles )]
    return tile_indices

def main():
    firstLine = True
    case = 1
    for line in fileinput.input():
        if firstLine:
            firstLine = False
            continue

        [tiles, complexity, students] = [int(num) for num in line.split()]
        
        
        print('CASE #' + str(case) + ': ', end='')
        for tile_index in pick_tiles_simple(tiles, complexity):
            print(tile_index, end=' ')
        print()
        case += 1


if __name__ == "__main__":
    main()
