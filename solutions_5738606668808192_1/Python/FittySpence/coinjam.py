global toGenerate
toGenerate = 500

def stringify(arr):
    out = ""
    for i in arr:
        out = out + str(i)
    return out   
            
def generateJamcoinsRecursive(arr, minimum):
    global toGenerate
    if toGenerate == 0:
        return
    print(stringify(arr) + " 3 2 5 2 7 2 3 2 7")
    toGenerate -= 1
    for i in range(minimum, len(arr) - 4):
        if(arr[i] == 0 and arr[i + 3] == 0):
            arr[i] = 1
            arr[i + 3] = 1
            generateJamcoinsRecursive(arr, i + 1)
            arr[i] = 0
            arr[i + 3] = 0
            if toGenerate == 0:
                return
    
def generateJamcoinsBase(size):
    arr = [0 for i in range(0, size)]
    arr[0] = 1
    arr[3] = 1
    arr[-1] = 1
    arr[-4] = 1
    generateJamcoinsRecursive(arr, 1)
    
    
generateJamcoinsBase(32)