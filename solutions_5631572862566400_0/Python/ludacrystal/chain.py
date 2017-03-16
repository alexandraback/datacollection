t = int(raw_input().strip())

class Node:
    def __init__(self, val):
        self.val = val
        self.children = []

    def addChild(self, child):
        self.children.append(child)

def get_length(node):
    children = node.children
    if len(children) == 0:
        return 1

    else:
        child_lengths = []
        for child in children:
            child_lengths.append(get_length(child))

        return max(child_lengths) + 1

def is_child_of(parent, child):
    #print("is " + str(child.val) + " a child of " + str(parent.val))
    children = parent.children

    for pchild in children:
        #print("checking child " + str(pchild.val))
        if pchild.val == child.val or is_child_of(pchild, child):
            #print("YES")
            return True
    #print("NO")
    return False

def get_max_friends(friend_list):
    if len(friend_list) < 1:
        return 0

    #made list of nodes
    node_list = []
    for i in range(0, len(friend_list)):
        new_node = Node(i + 1)
        node_list.append(new_node)

    #then, we set the values
    for i in range(0, len(friend_list)):
        parent = friend_list[i]
        parent_node = node_list[parent - 1]
        child_node = node_list[i]

        
        if not is_child_of(child_node, parent_node):
            parent_node.addChild(node_list[i])
            #print("added child " + str(node_list[i].val) + " to " + str(parent_node.val))
    #finally, we get the length of each node
    max_length = -1
    for i in range(0, len(friend_list)):
        cur_length = get_length(node_list[i])
        if len(node_list[i].children) > 1:
            cur_length = cur_length + 1
        #print("length of " + str(i + 1) + " is " + str(cur_length))
        if cur_length > max_length:
            max_length = cur_length

    return cur_length

#for each test case
for i in range(1, t + 1):
    #total number of friends in class
    n = int(raw_input().strip())
    friend_list = [int(x) for x in raw_input().strip().split()]
    max_friends = get_max_friends(friend_list)

    print("Case #" + str(i) + ": " + str(max_friends))

