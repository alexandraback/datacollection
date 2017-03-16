//Importa o Scanner
import java.util.Scanner;


public class Main {
    
    public Main(){
        
        //Cria uma instancia de Scanner passando o System.in
        Scanner leitor = new Scanner(System.in);
        
        //Pega a próxima variável digitada do tipo da função, para String é só usar leitor.next
        int numeroTestes = leitor.nextInt();
        //Na maratona não tem o número de testes, esse try serve para o programa parar quando chegar no fim do documento
        try{
            //Na maratona aqui vai um while(true)
            int numeroColunas;
            for(int j = 1; j <= numeroTestes; j++){
                int numeroCasos = leitor.nextInt();
                int casos[][] = new int[numeroCasos][3];
                for(int i = 0; i < numeroCasos; i++){
                    casos[i][0] = leitor.nextInt();
                    casos[i][1] = leitor.nextInt();
                    casos[i][2] = 0;
                }
                
                boolean semResultado = false;
                int estrelas = 0;
                int resposta = 0;
                
                while(true){
                    boolean testarUma = true;
                    for(int i = 0; i < numeroCasos; i++){
                        if(casos[i][2] == 0 && casos[i][1] <= estrelas){
                            estrelas += 2;
                            resposta += 1;
                            casos[i][2] = 2;
                            testarUma = false;
                            break;
                        }
                        else if(casos[i][2] == 1 && casos[i][1] <= estrelas){
                            estrelas += 1;
                            resposta += 1;
                            casos[i][2] = 2;
                            testarUma = false;
                            break;
                        }
                    }
                    boolean tooBad = false;
                    if(testarUma){
                        tooBad = true;
                        int maior = -1;
                        int indiceAtual = -1;
                        for(int i = 0; i < numeroCasos; i++){
                            if(casos[i][2] == 0 && casos[i][0] <= estrelas && casos[i][1] > maior){
                                maior = casos[i][1];
                                indiceAtual = i;
                            }
                        }
                        
                        if(indiceAtual > -1){
                            estrelas += 1;
                            resposta += 1;
                            casos[indiceAtual][2] = 1;
                            tooBad = false;
                        }
                    }
                    
                    
                    boolean terminou = true;
                    for(int i = 0; i < numeroCasos; i++){
                        if(casos[i][2] < 2){
                            terminou = false;
                            break;
                        }
                    }    
                   
                   if(terminou){
                       break;
                   }
                       
                    if(tooBad){
                        semResultado = true;
                        break;
                    }
                }
                
                if(semResultado){
                    System.out.println("Case #" + j + ": Too Bad");
                }
                else{
                    System.out.println("Case #" + j + ": " + resposta);
                }
            }
        }
        catch(Throwable e){
        
        }
    }
    
    public static void main(String[] args) {
        new Main();
    }//*/
}
