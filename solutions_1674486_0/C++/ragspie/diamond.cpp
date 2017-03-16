#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Global variables
//#define DEBUG 1
#define FINAL 1

#ifdef DEBUG
#define LOG(x,...)      if(DEBUG)\
{\
    printf(x,__VA_ARGS__);\
    printf("\n");\
    fflush(NULL);\
}\



#define LOG_S(x)        if(DEBUG)\
{\
    printf(x);\
    printf("\n");\
    fflush(NULL);\
}\

#endif /*DEBUG*/

#ifdef FINAL
#define LOG(x,...) ;
#define LOG_S(x)   ;
#endif /*FINAL*/


bool graph[1000][1000];
int total_classes;

void print_graph() {
//    for(int i=0;i<total_classes;i++) {
//        for(int j=0;j<total_classes;j++) {
//            printf("%d ", graph[i][j]);
//        }
//        printf("\n");
//    }
}

int find_node( bool* nodes_traversed, int current_node, int target_node) {
    LOG("find_node: %d %d", current_node, target_node);
    //for(int i=0;i<total_classes;i++) 
    //    printf("%d ", nodes_traversed[i]);
    //printf("\n");

    int num_paths_found=0;
    for(int i=0;i<total_classes;i++) {

        if(i==current_node)
            continue;

        if(nodes_traversed[i]==true || graph[current_node][i]==false) { 
            continue;
        }

        if(i==target_node) {
            num_paths_found++;
            continue;
        }

        nodes_traversed[current_node]=true;
        num_paths_found+=find_node(nodes_traversed, i, target_node);
    }

    LOG("Returning: %d", num_paths_found);
    return num_paths_found;
}

bool get_answer() {

    //from node
    for(int i=0; i<total_classes; i++) {
        LOG("Starting from node: %d", i);
//        nodes_traversed[i] = true;
        
        //to node
        for(int j=0;j<total_classes;j++) {
            LOG("\tStarting to node: %d", j);
//        nodes_traversed[i] = true;
            bool* nodes_traversed = (bool*)calloc(total_classes,sizeof(bool));
            int num_paths_found=0;
            if(j==i) {
                continue;
            }
                    
            num_paths_found+=find_node(nodes_traversed, i, j);
            if(num_paths_found>=2) {
                free(nodes_traversed);
                LOG("Returning true: %d",num_paths_found);
                return true;
            }
            free(nodes_traversed);
        }
    }    
    LOG_S("Returning false");
    return false;
}


int main(int argc, char* argv[])
{
    FILE *test_file, *output_file;
    bool output;

    int num_test_cases=0;

    if(argc!=3) {           
        printf("Invalid number of arguments.\n Usage <test_file> <output_file>");
        exit(1);
    }

    test_file    = fopen(argv[1], "r");
    output_file  = fopen(argv[2], "w");

    //first line of test file is the number of test_cases
    fscanf(test_file, "%d\n",&num_test_cases);
    LOG("Number of test cases: %d", num_test_cases);

    //reading test case and calling output function
    for(int i=1;i<=num_test_cases;i++) {
        LOG("Starting run number %d",i);

        fscanf(test_file, "%d\n",&total_classes);

        for(int j=0;j<total_classes;j++) {
            for(int k=0;k<total_classes;k++) {
                graph[j][k]=0;
            }
        }

        for(int j=0;j<total_classes;j++) {

            int num_inherited=0;

            fscanf(test_file, "%d",&num_inherited);

            for(int k=0;k<num_inherited;k++) {
                int node=0;
                fscanf(test_file, " %d",&node);

                graph[j][node-1]=true;
            }
            fscanf(test_file, "\n");
        }

        print_graph();
        output = get_answer();

        LOG("Outputting result: %d", output);
        fprintf(output_file, "Case #%d: ", i);
        if(output==true)
            fprintf(output_file, "Yes\n");
        else 
            fprintf(output_file, "No\n");
        //fprintf(output_file, "\n");
    }

    fclose(test_file);
    fclose(output_file);
}
