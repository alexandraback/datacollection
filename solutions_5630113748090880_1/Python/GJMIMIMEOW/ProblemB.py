#file1 = open(r"C:\Users\Wu Jui Hsuan\Desktop\GCJ\proB.txt","r")
#file = open(r"C:\Users\Wu Jui Hsuan\Desktop\GCJ\resultB.txt","w")

def mp():
    global file1  
    return map(int,file1.readline().split())
def ip():
    global file1  
    return file1.readline()
def it():
    global file1  
    return int(file1.readline())
def lt():  
    global file1
    return list(map(int,file1.readline().split()))
def pt(x):
    global file  
    file.write(x)
def ptlist(l): 
    global file
    file.write(' '.join(map(str,l)))
#"Case #d: "

