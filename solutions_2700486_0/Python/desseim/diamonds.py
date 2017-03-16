import sys

def bottom_left(diamond_point):
    return (diamond_point[0]-1, diamond_point[1]-1)
def bottom_right(diamond_point):
    return (diamond_point[0]+1, diamond_point[1]-1)
def under(diamond_point):
    return (diamond_point[0], diamond_point[1]-2)

def prob(diamond_grid, target_point, start_point, nb_remaining_diamonds):
    diamond_point = start_point
    bottom_left_in_grid = bottom_left(diamond_point) in diamond_grid
    bottom_right_in_grid = bottom_right(diamond_point) in diamond_grid

    if diamond_point[1] == 0 or (bottom_left_in_grid and bottom_right_in_grid):  #diamond settled
        if diamond_point == target_point: return 1
        else:
            #put this diamond in the grid and continue with the remaining ones
            if nb_remaining_diamonds <= 0: return 0
            else:
                new_grid = diamond_grid[:]
                new_grid.append(diamond_point)
                new_start_height = max(start_point[1], diamond_point[1]+2)
                return prob(new_grid, target_point, (0, new_start_height), nb_remaining_diamonds - 1)
    else: #diamond didn't settle, move it
        #import pdb; pdb.set_trace()
        if bottom_left_in_grid:
            if bottom_right(diamond_point) in diamond_grid: sys.exit('algo error !!')
            else: #slide to the right
                diamond_point = bottom_right(diamond_point)
        elif bottom_right_in_grid: #nothing on left but something on right, slide to the left
            diamond_point = bottom_left(diamond_point)
        else: #nothing on left nor right
            if under(diamond_point) not in diamond_grid: #nothing under, just slide down
                diamond_point = (diamond_point[0], diamond_point[1]-1)
            else: #something under, need to choose
                left_prob = 0.5 * prob(diamond_grid, target_point, bottom_left(diamond_point), nb_remaining_diamonds)
                right_prob = 0.5 * prob(diamond_grid, target_point, bottom_right(diamond_point), nb_remaining_diamonds)
                return left_prob + right_prob
        return prob(diamond_grid, target_point, diamond_point, nb_remaining_diamonds)

def start_prob(nb_diamonds, target_point):
    return prob([], target_point, (0, 0), nb_diamonds-1)

def main(input_file_name, output_file_name):
    input_file = open(input_file_name, 'rU')
    output_file = open(output_file_name, 'w')
    for case in range(int(input_file.readline())):
        nb_diamonds, target_point_x, target_point_y = [int(x) for x in input_file.readline().split()]
        prob = start_prob(nb_diamonds, (target_point_x, target_point_y))
        prob_str_format = "{:.6g}"
        print('case ' + str(case) + ': ' + prob_str_format.format(prob))
        output_file.write('Case #' + str(case+1) + ': ' + prob_str_format.format(prob) + '\n')
    input_file.close()
    output_file.close()


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
