def search(parents, list_classes, classes, class_num):
  for parent in list_classes[class_num-1]:
    num_parent = int(parent)
    if num_parent in parents:
      return True
    parents.append(num_parent)
    if search(parents, list_classes, classes, num_parent):
      return True
  return False

def main():
  try:
    f_in = open('A-small-attempt0.in', 'r')
    f_out = open('output.txt', 'w')

    cnt = int(f_in.readline())
    for i in range(0,cnt):
      list_classes = []
      classes = int(f_in.readline())
      for x in range(1, classes+1):
        list_classes.append((f_in.readline().split())[1:])
      diamond = False
      #print list_classes
      #print classes
      for x in range(1, classes+1):
        parents = []
        if search(parents, list_classes, classes, x):
          diamond = True
          #print parents
          break
        
      if diamond:
        f_out.write("Case #%d: Yes\n" % (i+1))
      else:
        f_out.write("Case #%d: No\n" % (i+1))
        
    f_in.close()
    f_out.close()
  except Exception as ex:
    print ex
    
  raw_input()
  
if __name__ == '__main__':
  main()