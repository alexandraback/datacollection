'''
Created on Apr 14, 2012

@author: disqiu
'''

def read_file(file_name):
    read = open(file_name,"r")
    return read.readlines()
    
def write_file(list_string,file_name):
    out = open(file_name,"w")
    out.writelines(list_string)
    out.close()
