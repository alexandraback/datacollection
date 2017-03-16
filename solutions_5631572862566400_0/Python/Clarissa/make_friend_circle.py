#Let's make a BFF circle!
import fileinput

def find_longest_end(BFF_indices, end_node):
    #Finds the longest path ending in the end node not yet visited
    number_children = len(BFF_indices)
    longest_path = 0
    visited_list = [False]*number_children
    visited_list[BFF_indices[end_node]] = True
    visited_list[end_node] = True
    
    for index in range(number_children):
        # Skip visited nodes
        if visited_list[index]:
            continue
        starting_node = index
        already_visited = visited_list[:]
        already_visited[starting_node] = True
        next_node = BFF_indices[starting_node]
        
        # At the end of this we have hit a visited node.
        path_length = 1
        while not already_visited[next_node]:
            already_visited[next_node] = True
            next_node = BFF_indices[next_node]
            path_length += 1
        
        # Path ends in our special node, count path
        if next_node == end_node:
            if path_length > longest_path:
                longest_path = path_length
    
    return longest_path + 1
    
def cycle_length(BFF_indices, starting_node):
    # -1 = no cycle
    number_children = len(BFF_indices)
    already_visited = [False]*number_children
    already_visited[starting_node] = True
    next_node = BFF_indices[starting_node]
    
    # At the end of this we have traversed a cycle of some length.
    # Path length is also the number of kids in the circle
    cycle_length = 1
    while not already_visited[next_node]:
        already_visited[next_node] = True
        next_node = BFF_indices[next_node]
        cycle_length += 1
    
    #If we end up on the starting node, we have a cycle containing our
    # starting node
    if next_node == starting_node:
        #We have a cycle starting with our starting node
        return cycle_length
    else:
        return -1

def find_maximal_bff_circle(BFF_indices):
    # Searches a list of indices of BFFs for the longest path.
    number_children = len(BFF_indices)
    longest_path = 0
    two_cycle_nodes = 0
    for index in range(number_children):
        this_index_cycle_length = cycle_length(BFF_indices, index)
        
        if this_index_cycle_length > longest_path:
            longest_path = this_index_cycle_length
        
        if this_index_cycle_length == 2:
            two_cycle_nodes += 1
            friend_index = BFF_indices[index]
            path_length = find_longest_end(BFF_indices, index)
            path_length += find_longest_end(BFF_indices, friend_index)
            if path_length > longest_path:
                longest_path = path_length
    
    # Can have a circle of happy two cycles
    if two_cycle_nodes > longest_path:
        longest_path = two_cycle_nodes
    
    return longest_path

def main():
    firstLine = True
    even_line = True #Will be false 
    case = 1
    for line in fileinput.input():
        even_line = not even_line
        if firstLine:
            firstLine = False
            continue
        if even_line:
            continue

        BFF_indices = [int(index)-1 for index in line.strip().split()]
        print('Case #' + str(case) + ': ', end='')
        print(find_maximal_bff_circle(BFF_indices))
        
        case += 1

if __name__ == '__main__':
    main()
